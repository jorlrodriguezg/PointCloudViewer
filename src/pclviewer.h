#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

//#include <Eigen/StdVector>

// Qt
#include <QMainWindow>
#include <QDoubleSpinBox>
#include <QListWidgetItem>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/common/centroid.h>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>


// Forward declaration for commonly used objects
class Command;
class CommandQueue;
class Selection;
class CopyBuffer;
class Cloud;

// Some helpful typedef's for commonly used objects
/// The type for XYZ
typedef pcl::PointXYZ PointXYZ;

/// The type for the 3D points in the point cloud.
typedef pcl::PointXYZRGB Point3D;

/// The type used as internal representation of a cloud object.
typedef pcl::PointCloud<Point3D> Cloud3D;

/// The type for the 3D point vector in the point cloud.
typedef pcl::PointCloud<Point3D>::VectorType Point3DVector;

/// The type of the voxel grid
typedef pcl::VoxelGrid<Point3D> VoxelGrid;

/// The type of the writer
typedef pcl::PCDWriter PCDWriter;

/// The type for statistical removal
typedef pcl::StatisticalOutlierRemoval<Point3D> StatisticalOutlierRemoval;

/// The type for boost shared pointer pointing to a PCL cloud object.
typedef Cloud3D::Ptr PclCloudPtr;

/// The type for Cloud 3D vetor
typedef std::vector<PclCloudPtr, Eigen::aligned_allocator<PclCloudPtr> > CloudVectorType;

/// The type for boost shared pointer pointing to a cloud object
typedef boost::shared_ptr<Cloud> CloudPtr;

/// The type for boost shared pointer pointing to a constant cloud
/// object
typedef boost::shared_ptr<const Cloud> ConstCloudPtr;

/// The type for boost shared pointer pointing to a selection buffer
typedef boost::shared_ptr<Selection> SelectionPtr;

/// The type for boost shared pointer pointing to a constant selection
/// buffer
typedef boost::shared_ptr<const Selection> ConstSelectionPtr;

/// The type for boost shared pointer pointing to a copy buffer
typedef boost::shared_ptr<CopyBuffer> CopyBufferPtr;

/// The type for boost shared pointer pointing to a constant copy
/// buffer
typedef boost::shared_ptr<const CopyBuffer> ConstCopyBufferPtr;

/// The type for boost shared pointer pointing to a command object
typedef boost::shared_ptr<Command> CommandPtr;

/// The type used for vectors holding the indices of points in a cloud
typedef std::vector<unsigned int> IndexVector;

/// The type used for vectors holding the constant indices of points in
/// a cloud
typedef std::vector<const int> ConstIndexVector;

/// The type for boost shared pointer pointing to a command queue
/// object
typedef boost::shared_ptr<CommandQueue> CommandQueuePtr;

/// The type for bit masks used for recognizing key pressed by user.
typedef unsigned int BitMask;

namespace Ui
{
  class PCLViewer;
}

class PCLViewer : public QMainWindow
{
  Q_OBJECT

public:
  explicit PCLViewer (QWidget *parent = 0);
  ~PCLViewer ();

public Q_SLOTS:

  void
  pSliderValueChanged (int value);

  std::string
  point2underscore(std::string text);


protected:
  pcl::visualization::PCLVisualizer::Ptr viewer;

  Cloud3D::Ptr cloud;
  Cloud3D::Ptr cloud_filtered;
  CloudVectorType sourceClouds;
  //Point3DVector sourceClouds;

  unsigned int red;
  unsigned int green;
  unsigned int blue;

  //Voxel grid
  float leaf_inputX;
  float leaf_inputY;
  float leaf_inputZ;

  //Statistical removal
  float mean_input;
  float std_input;

  // Key for cloud selection
  std::map<std::string, int> KeyFor_Cloud;

  int cloud_num;

private slots:
  void on_actionAbrir_triggered();

  void on_voxel_grid_Button_clicked();


  void on_doubleSpinBox_valueChanged(double arg1);

  void on_doubleSpinBox_2_valueChanged(double arg1);

  void on_doubleSpinBox_3_valueChanged(double arg1);

  void on_actionGuardar_triggered();

  void on_doubleSpinBox_4_valueChanged(double arg1);

  void on_doubleSpinBox_5_valueChanged(double arg1);

  void on_StatisticalRemovalButton_clicked();

  void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
  void update_numcapa();
  //Right click listWidget
  void ProvideContextMenu(const QPoint &);

private:
  Ui::PCLViewer *ui;

};
