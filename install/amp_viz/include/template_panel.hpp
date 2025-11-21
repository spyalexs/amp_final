#pragma once

#include <rviz_common/panel.hpp>

class TemplatePanel : public rviz_common::Panel{
    Q_OBJECT
    public:
        explicit TemplatePanel(QWidget * parent = 0);
        ~TemplatePanel() override;
};