/********************************************************************************
** Form generated from reading UI file 'template_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATE_PANEL_H
#define UI_TEMPLATE_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Template_Panel
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *launch_angle_input;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLineEdit *launch_velocity_input;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *launch_heading_input;
    QPushButton *launch_button;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLineEdit *read_x_pos;
    QLineEdit *set_x_pos;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *read_y_pos;
    QLineEdit *set_y_pos;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLineEdit *read_heading;
    QLineEdit *set_heading;
    QPushButton *set_position_button;

    void setupUi(QWidget *Template_Panel)
    {
        if (Template_Panel->objectName().isEmpty())
            Template_Panel->setObjectName(QString::fromUtf8("Template_Panel"));
        Template_Panel->resize(400, 400);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Template_Panel->sizePolicy().hasHeightForWidth());
        Template_Panel->setSizePolicy(sizePolicy);
        Template_Panel->setMinimumSize(QSize(400, 400));
        verticalLayoutWidget = new QWidget(Template_Panel);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 391, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        launch_angle_input = new QLineEdit(verticalLayoutWidget);
        launch_angle_input->setObjectName(QString::fromUtf8("launch_angle_input"));

        verticalLayout_2->addWidget(launch_angle_input);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        launch_velocity_input = new QLineEdit(verticalLayoutWidget);
        launch_velocity_input->setObjectName(QString::fromUtf8("launch_velocity_input"));

        verticalLayout_4->addWidget(launch_velocity_input);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        launch_heading_input = new QLineEdit(verticalLayoutWidget);
        launch_heading_input->setObjectName(QString::fromUtf8("launch_heading_input"));

        verticalLayout_3->addWidget(launch_heading_input);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);

        launch_button = new QPushButton(verticalLayoutWidget);
        launch_button->setObjectName(QString::fromUtf8("launch_button"));

        verticalLayout->addWidget(launch_button);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_7->addWidget(label_4);

        read_x_pos = new QLineEdit(verticalLayoutWidget);
        read_x_pos->setObjectName(QString::fromUtf8("read_x_pos"));
        read_x_pos->setReadOnly(true);

        verticalLayout_7->addWidget(read_x_pos);

        set_x_pos = new QLineEdit(verticalLayoutWidget);
        set_x_pos->setObjectName(QString::fromUtf8("set_x_pos"));

        verticalLayout_7->addWidget(set_x_pos);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        read_y_pos = new QLineEdit(verticalLayoutWidget);
        read_y_pos->setObjectName(QString::fromUtf8("read_y_pos"));
        read_y_pos->setReadOnly(true);

        verticalLayout_5->addWidget(read_y_pos);

        set_y_pos = new QLineEdit(verticalLayoutWidget);
        set_y_pos->setObjectName(QString::fromUtf8("set_y_pos"));

        verticalLayout_5->addWidget(set_y_pos);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        read_heading = new QLineEdit(verticalLayoutWidget);
        read_heading->setObjectName(QString::fromUtf8("read_heading"));
        read_heading->setReadOnly(true);

        verticalLayout_6->addWidget(read_heading);

        set_heading = new QLineEdit(verticalLayoutWidget);
        set_heading->setObjectName(QString::fromUtf8("set_heading"));

        verticalLayout_6->addWidget(set_heading);


        horizontalLayout_5->addLayout(verticalLayout_6);


        horizontalLayout->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout);

        set_position_button = new QPushButton(verticalLayoutWidget);
        set_position_button->setObjectName(QString::fromUtf8("set_position_button"));

        verticalLayout->addWidget(set_position_button);


        retranslateUi(Template_Panel);

        QMetaObject::connectSlotsByName(Template_Panel);
    } // setupUi

    void retranslateUi(QWidget *Template_Panel)
    {
        Template_Panel->setWindowTitle(QCoreApplication::translate("Template_Panel", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Template_Panel", "Launch Angle", nullptr));
        label_2->setText(QCoreApplication::translate("Template_Panel", "Launch Velocity", nullptr));
        label_3->setText(QCoreApplication::translate("Template_Panel", "Launch Heading", nullptr));
        launch_button->setText(QCoreApplication::translate("Template_Panel", "Launch!", nullptr));
        label_4->setText(QCoreApplication::translate("Template_Panel", "Robot X Position", nullptr));
        label_5->setText(QCoreApplication::translate("Template_Panel", "Robot Y Position", nullptr));
        label_6->setText(QCoreApplication::translate("Template_Panel", "Robot Heading", nullptr));
        set_position_button->setText(QCoreApplication::translate("Template_Panel", "Set Position!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Template_Panel: public Ui_Template_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATE_PANEL_H
