/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QAction *actionAbrir;
    QAction *actionGuardar;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QLabel *label_4;
    QSlider *horizontalSlider_p;
    QLCDNumber *lcdNumber_p;
    QVTKWidget *qvtkWidget;
    QGroupBox *groupBox_2;
    QTabWidget *tabWidget;
    QWidget *filtros;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox_3;
    QPushButton *voxel_grid_Button;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_3;
    QGroupBox *groupBox_4;
    QPushButton *StatisticalRemovalButton;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_5;
    QScrollBar *verticalScrollBar;
    QWidget *clustering;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QStringLiteral("PCLViewer"));
        PCLViewer->resize(1295, 808);
        PCLViewer->setMinimumSize(QSize(0, 0));
        PCLViewer->setMaximumSize(QSize(5000, 5000));
        actionAbrir = new QAction(PCLViewer);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        QIcon icon;
        icon.addFile(QStringLiteral("resources/64x64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbrir->setIcon(icon);
        actionGuardar = new QAction(PCLViewer);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("resources/save64x64.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionGuardar->setIcon(icon1);
        centralwidget = new QWidget(PCLViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(16777215, 250));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        groupBox->setFont(font);
        groupBox->setAutoFillBackground(false);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 121, 21));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_4->setFont(font1);
        horizontalSlider_p = new QSlider(groupBox);
        horizontalSlider_p->setObjectName(QStringLiteral("horizontalSlider_p"));
        horizontalSlider_p->setGeometry(QRect(10, 50, 160, 16));
        horizontalSlider_p->setMinimum(1);
        horizontalSlider_p->setMaximum(6);
        horizontalSlider_p->setValue(2);
        horizontalSlider_p->setOrientation(Qt::Horizontal);
        lcdNumber_p = new QLCDNumber(groupBox);
        lcdNumber_p->setObjectName(QStringLiteral("lcdNumber_p"));
        lcdNumber_p->setGeometry(QRect(180, 40, 51, 31));
        lcdNumber_p->setDigitCount(1);
        lcdNumber_p->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_p->setProperty("intValue", QVariant(2));

        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy1);
        qvtkWidget->setCursor(QCursor(Qt::CrossCursor));

        gridLayout->addWidget(qvtkWidget, 0, 1, 3, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setFont(font);
        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 30, 241, 351));
        tabWidget->setFont(font1);
        filtros = new QWidget();
        filtros->setObjectName(QStringLiteral("filtros"));
        scrollArea = new QScrollArea(filtros);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 10, 231, 291));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 229, 289));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 10, 211, 141));
        voxel_grid_Button = new QPushButton(groupBox_3);
        voxel_grid_Button->setObjectName(QStringLiteral("voxel_grid_Button"));
        voxel_grid_Button->setGeometry(QRect(120, 70, 83, 28));
        QFont font2;
        font2.setFamily(QStringLiteral("Cantarell"));
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        voxel_grid_Button->setFont(font2);
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 102, 101));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setCursor(QCursor(Qt::ArrowCursor));
        doubleSpinBox->setReadOnly(false);
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(0);
        doubleSpinBox->setMaximum(1000);
        doubleSpinBox->setSingleStep(1);
        doubleSpinBox->setValue(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setEnabled(true);
        doubleSpinBox_2->setCursor(QCursor(Qt::ArrowCursor));
        doubleSpinBox_2->setWrapping(false);
        doubleSpinBox_2->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_2->setDecimals(1);
        doubleSpinBox_2->setMinimum(0);
        doubleSpinBox_2->setMaximum(1000);
        doubleSpinBox_2->setSingleStep(1);
        doubleSpinBox_2->setValue(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        doubleSpinBox_3 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setCursor(QCursor(Qt::ArrowCursor));
        doubleSpinBox_3->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
        doubleSpinBox_3->setSuffix(QStringLiteral(""));
        doubleSpinBox_3->setDecimals(1);
        doubleSpinBox_3->setMinimum(0);
        doubleSpinBox_3->setMaximum(1000);
        doubleSpinBox_3->setSingleStep(1);
        doubleSpinBox_3->setValue(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_3);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 150, 211, 131));
        StatisticalRemovalButton = new QPushButton(groupBox_4);
        StatisticalRemovalButton->setObjectName(QStringLiteral("StatisticalRemovalButton"));
        StatisticalRemovalButton->setGeometry(QRect(60, 100, 83, 28));
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 186, 66));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        doubleSpinBox_4 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setCursor(QCursor(Qt::ArrowCursor));
        doubleSpinBox_4->setReadOnly(false);
        doubleSpinBox_4->setDecimals(1);
        doubleSpinBox_4->setMinimum(0);
        doubleSpinBox_4->setMaximum(1000);
        doubleSpinBox_4->setSingleStep(1);
        doubleSpinBox_4->setValue(1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_4);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        doubleSpinBox_5 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setCursor(QCursor(Qt::ArrowCursor));
        doubleSpinBox_5->setReadOnly(false);
        doubleSpinBox_5->setDecimals(1);
        doubleSpinBox_5->setMinimum(0);
        doubleSpinBox_5->setMaximum(1000);
        doubleSpinBox_5->setSingleStep(1);
        doubleSpinBox_5->setValue(1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_5);

        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(210, -1, 20, 311));
        verticalScrollBar->setOrientation(Qt::Vertical);
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(filtros, QString());
        clustering = new QWidget();
        clustering->setObjectName(QStringLiteral("clustering"));
        tabWidget->addTab(clustering, QString());

        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        PCLViewer->setCentralWidget(centralwidget);
        groupBox->raise();
        qvtkWidget->raise();
        groupBox_2->raise();
        listWidget->raise();
        menuBar = new QMenuBar(PCLViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1295, 25));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        PCLViewer->setMenuBar(menuBar);
        toolBar = new QToolBar(PCLViewer);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        PCLViewer->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionGuardar);
        toolBar->addAction(actionAbrir);
        toolBar->addAction(actionGuardar);

        retranslateUi(PCLViewer);
        QObject::connect(horizontalSlider_p, SIGNAL(sliderMoved(int)), lcdNumber_p, SLOT(display(int)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "Point Cloud Processing", Q_NULLPTR));
        actionAbrir->setText(QApplication::translate("PCLViewer", "&Abrir", Q_NULLPTR));
        actionGuardar->setText(QApplication::translate("PCLViewer", "&Guardar", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("PCLViewer", "Visualizaci\303\263n", Q_NULLPTR));
        label_4->setText(QApplication::translate("PCLViewer", "Tama\303\261o del punto", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("PCLViewer", "Procesamiento", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("PCLViewer", "Voxel grid (cm)", Q_NULLPTR));
        voxel_grid_Button->setText(QApplication::translate("PCLViewer", "Ejecutar", Q_NULLPTR));
        label_5->setText(QApplication::translate("PCLViewer", "X", Q_NULLPTR));
        label_6->setText(QApplication::translate("PCLViewer", "Y", Q_NULLPTR));
        doubleSpinBox_2->setSpecialValueText(QString());
        label_7->setText(QApplication::translate("PCLViewer", "Z", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("PCLViewer", "Statistical removal", Q_NULLPTR));
        StatisticalRemovalButton->setText(QApplication::translate("PCLViewer", "Ejecutar", Q_NULLPTR));
        label_8->setText(QApplication::translate("PCLViewer", "Media (cm)", Q_NULLPTR));
        label_9->setText(QApplication::translate("PCLViewer", "Desv. est\303\241ndar", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(filtros), QApplication::translate("PCLViewer", "Filtros", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(clustering), QApplication::translate("PCLViewer", "Segmentaci\303\263n", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("PCLViewer", "Archi&vo", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("PCLViewer", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
