#include "pclviewer.h"
#include "ui_pclviewer.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

// setup cloud stak layer
//std::vector<PclCloudPtr, Eigen::aligned_allocator<PclCloudPtr> > sourceClouds;


PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::PCLViewer)
{
  ui->setupUi (this);
  this->setWindowTitle ("Point Cloud Processing");

  // Setup the cloud pointer
  cloud.reset (new Cloud3D);
  // The number of points in the cloud
  cloud->points.resize (10000);

  cloud_filtered.reset (new Cloud3D);



  //sourceClouds.reserve(10);

  // The default color
  red   = 200;
  green = 128;
  blue  = 128;

  //The cloud number
  cloud_num =0;

  // The default voxel leaf size (1cm)
  leaf_inputX = 0.01f;
  leaf_inputY = 0.01f;
  leaf_inputZ = 0.01f;

  // the default for Statistical Removal
  mean_input = 50.0;
  std_input = 1.0;


  // Fill the cloud with some points
  for (size_t i = 0; i < cloud->points.size (); ++i)
  {
    cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);

    cloud->points[i].r = red;
    cloud->points[i].g = green;
    cloud->points[i].b = blue;
  }
  ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
  connect(ui->listWidget, SIGNAL(customContextMenuRequested(const QPoint &)),
          this, SLOT(ProvideContextMenu(const QPoint &)));
  //sourceClouds.push_back(cloud);
  // Set up the QVTK window
  viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
  double R = .25;
  double G = .26;
  double B = .26;
  viewer->setBackgroundColor (R,G,B);
  //viewer->addCoordinateSystem(1.0);
  ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
  viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
  ui->qvtkWidget->update ();

  // Connect point size slider
  connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

  //viewer->addPointCloud (sourceClouds[0], "cloud");
  viewer->addPointCloud (cloud, "cloud");
  pSliderValueChanged (2);
  ui->listWidget->addItem("cloud");
  viewer->resetCamera ();
  ui->qvtkWidget->update ();

}

void
PCLViewer::pSliderValueChanged (int value)
{
/*
  // Get the pointer to the currently selected item.
  QListWidgetItem *item = ui->listWidget->currentItem();

  QString nombre_capa = item->text();

  std::cout << "Nombre capa activa: " << nombre_capa.toStdString() << std::endl;
  int cloud_selected_key = 0;
  cloud_selected_key = KeyFor_Cloud[nombre_capa.toStdString()];

  std::cout << "Id seleccionado: " << cloud_selected_key << std::endl;
  std::string nombre_layer = nombre_capa.toStdString();*/

  //viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, nombre_layer);
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
  ui->qvtkWidget->update ();
}

PCLViewer::~PCLViewer ()
{
  delete ui;
}

void PCLViewer::ProvideContextMenu(const QPoint &pos)
{
    QPoint item = ui->listWidget->mapToGlobal(pos);
    QMenu submenu;
    submenu.addAction("Save as");
    submenu.addAction("Delete");
    QAction* rightClickItem = submenu.exec(item);
    if (rightClickItem && rightClickItem->text().contains("Delete") )
    {
        ui->listWidget->takeItem(ui->listWidget->indexAt(pos).row());
    }
}

void PCLViewer::on_actionAbrir_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this,
            tr("Abrir nube de puntos"), "",
            tr("PCD (*.pcd);;All Files (*)"));

    if (fileNames.isEmpty())
        return;
    else {        
        //
        //Get user inputs

        QString item_name;
        int names = ui->listWidget->count();
        for(int i = 0; i < names; i++)
        {
            //allNamesAsAList << ui->listWidget->item(i)->text();
            item_name = ui->listWidget->item(i)->text();
            std::string item_str = item_name.toStdString();
            if(item_str.compare("cloud") ==0)
            {
                viewer->removePointCloud("cloud");
                QListWidgetItem *item_to_remove = ui->listWidget->item(i);
                delete ui->listWidget->takeItem(ui->listWidget->row(item_to_remove));
            }

        }

        int i =0;
        int y =50;
        foreach (QString fileName, fileNames) {
            QFile inFile( fileName );
                if( !inFile.open( QIODevice::ReadOnly | QIODevice::Text ) )
                {
                    qDebug("Failed to open file for reading.");
                    return;
                }
                else
                {
                    const std::string file_name = fileName.toStdString();
                    QFileInfo fileInfo(inFile.fileName());
                    QString filename_only(fileInfo.fileName());
                    std::cout << "Nombre de achivo: " << filename_only.toStdString() << std::endl;
                    const std::string cloud_name = point2underscore(filename_only.toStdString());
                    QString nombre_layer = QString::fromStdString(cloud_name);
                    //const std::string cloud_name = filename_only.toStdString();
                    std::cout << "Nombre de la capa: " << cloud_name << std::endl;

                    //Cloud vector for clouds
                    PclCloudPtr sourceCloud(new Cloud3D);
                    if (pcl::io::loadPCDFile(file_name, *sourceCloud) == -1) //* load the file
                    {
                        PCL_ERROR ("Couldn't read file\n");
                        return;
                    }
                    else
                    {
                        std::cout << "Loaded "
                        << sourceCloud->width * sourceCloud->height
                        << " data points from "<<file_name
                        << std::endl;


                        sourceClouds.push_back(sourceCloud);

                        std::stringstream ss;
                        ss << "Cargados " << sourceCloud->width * sourceCloud->height << " puntos del archivo: "<< cloud_name;
                        std::string texto = ss.str();
                        //viewer->addPointCloud (sourceClouds[cloud_num], cloud_name);
                        viewer->addPointCloud (sourceClouds[cloud_num], cloud_name);
                        KeyFor_Cloud[cloud_name] = int(cloud_num);
                        std::cout << "Cargada nube " << cloud_name << " con id: " << cloud_num << std::endl;
                        update_numcapa();

                        viewer->addText (texto, 10,y,1,1,1);
                        ui->listWidget->addItem(nombre_layer);
                        viewer->resetCamera();
                        ui->qvtkWidget->update ();
                        y += 10;

                     }

                }

        }

    }

}

void PCLViewer::on_voxel_grid_Button_clicked()
{
    std::cout << "leaf input X: " << leaf_inputX;
    std::cout << " leaf input Y: " << leaf_inputY;
    std::cout << " leaf input Z: " << leaf_inputZ;

    // Get the pointer to the currently selected item.
    QListWidgetItem *item = ui->listWidget->currentItem();

    QString nombre_capa = item->text();

    std::cout << "Nombre capa activa: " << nombre_capa.toStdString() << std::endl;

    int cloud_selected_key = KeyFor_Cloud[nombre_capa.toStdString()];

    std::cout << "Id seleccionado: " << cloud_selected_key << std::endl;


    // Setup the cloud pointer
    //cloud_filtered.reset (new Cloud3D);
    PclCloudPtr sourceCloudFilter(new Cloud3D);

    VoxelGrid sor;
    sor.setInputCloud (sourceClouds[cloud_selected_key]);
    sor.setLeafSize (leaf_inputX, leaf_inputY, leaf_inputZ);
    sor.filter (*sourceCloudFilter);

    std::cerr << "PointCloud after filtering: " << sourceCloudFilter->width * sourceCloudFilter->height
           << " data points (" << pcl::getFieldsList (*sourceCloudFilter) << ").";

    sourceClouds.push_back(sourceCloudFilter);
    update_numcapa();

    std::stringstream stream;
    stream << "Voxel_grid_cloud" << cloud_num;
    //std::cout << "Nombre capa filtrada: " << stream.str() << std::endl;
    const std::string nombrestr = stream.str();
    KeyFor_Cloud[nombrestr] = int(cloud_num);
    std::cout << "Nombre capa filtrada: " << nombrestr << std::endl;

    viewer->addPointCloud (sourceClouds[cloud_num,0], nombrestr);

    std::cout << "Cargada nube " << stream.str() << " con id: " << cloud_num << std::endl;
    QString nombre_listW = QString::fromStdString(nombrestr);
    ui->listWidget->addItem(nombre_listW);
    viewer->resetCamera();
    ui->qvtkWidget->update ();
    sourceCloudFilter->clear();
}

void PCLViewer::on_doubleSpinBox_valueChanged(double arg1)
{
    leaf_inputX = (float) arg1/100;
}

void PCLViewer::on_doubleSpinBox_2_valueChanged(double arg1)
{
    leaf_inputY = (float) arg1/100;
}

void PCLViewer::on_doubleSpinBox_3_valueChanged(double arg1)
{
    leaf_inputZ = (float) arg1/100;
}

void PCLViewer::on_actionGuardar_triggered()
{
    // Get the pointer to the currently selected item.
    QListWidgetItem *item = ui->listWidget->currentItem();

    QString nombre_capa = item->text();

    std::cout << "Nombre capa activa: " << nombre_capa.toStdString() << std::endl;

    int cloud_selected_key = KeyFor_Cloud[nombre_capa.toStdString()];

    std::cout << "Id seleccionado: " << cloud_selected_key << std::endl;

    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Guardar nube de puntos"), "",
            tr("PCD (*.pcd);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        const std::string file_name = fileName.toStdString();
        PCDWriter writer;
        //writer.write<Point3D> (file_name, sourceClouds[cloud_selected_key,0], false);

    }

}

void PCLViewer::on_doubleSpinBox_4_valueChanged(double arg1)
{
    mean_input = (float) arg1/100;
}

void PCLViewer::on_doubleSpinBox_5_valueChanged(double arg1)
{
    std_input = (float) arg1/100;
}

void PCLViewer::on_StatisticalRemovalButton_clicked()
{
    std::cout << "Mean input:" << mean_input;
    std::cout << "Std multi trheshold input:" << std_input;

    // Get the pointer to the currently selected item.
    QListWidgetItem *item = ui->listWidget->currentItem();

    QString nombre_capa = item->text();

    std::cout << "Nombre capa activa: " << nombre_capa.toStdString() << std::endl;

    int cloud_selected_key = KeyFor_Cloud[nombre_capa.toStdString()];

    std::cout << "Id seleccionado: " << cloud_selected_key << std::endl;

    // Setup the cloud pointer
    cloud_filtered.reset (new Cloud3D);

    StatisticalOutlierRemoval sor;

    sor.setInputCloud (sourceClouds[cloud_selected_key]);
    sor.setMeanK (mean_input);
    sor.setStddevMulThresh (std_input);
    sor.filter (*cloud_filtered);

    std::cerr << "Cloud after filtering: " << std::endl;
    std::cerr << *cloud_filtered << std::endl;

    std::stringstream ss;
    ss << "Cargados " << cloud_filtered->width * cloud_filtered->height << " puntos de la nube filtrada";
    const std::string texto = ss.str();


    //viewer->removeAllPointClouds ();
    viewer->addPointCloud (cloud_filtered, "cloud_filtered");
    viewer->resetCamera ();
    viewer->updateText (texto, 10,750,200,200,200);
    ui->qvtkWidget->update ();
}

std::string PCLViewer::point2underscore(std::string text) {
    for(std::string::iterator it = text.begin(); it != text.end(); ++it) {
        if(*it == '.') {
            *it = '_';
        }
    }
    return text;
}

void PCLViewer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    // Get the pointer to the currently selected item.
    //QListWidgetItem *item = ui->listWidget->currentItem();

    QString nombre_capa = item->text();

    std::cout << "Nombre capa activa: " << nombre_capa.toStdString() << std::endl;
    int i = 0;
    i = KeyFor_Cloud[nombre_capa.toStdString()];

    std::cout << "Id seleccionado: " << i << std::endl;

    PclCloudPtr sourceCloud(new Cloud3D);
    Cloud3D points;

    //pcl::NdCopyPointEigenFunctor(sourceClouds[i],points);
    /*
    for (int j=1;j<20;j++){
        std::cout << sourceCloud.x << " " << sourceCloud.y << " " << sourceCloud.z << " " <<std::endl;
    }*/
/*
    pcl::CentroidPoint<PointXYZ> centroide;

    PointXYZ xyz_cloud;
    pcl::copyPoint(*sourceCloud, xyz_cloud);

    centroide.add( xyz_cloud );
    Point3D center;
    centroide.get(center);

    std::cout << "Centroide nube seleccionada: " << center.x <<" " << center.y << " " <<center.z << std::endl;

*/
}

void PCLViewer::update_numcapa()
{
     cloud_num = cloud_num + 1;
}
