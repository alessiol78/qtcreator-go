#pragma once

#include <QStandardItemModel>

#include <coreplugin/dialogs/ioptionspage.h>

#include "ui_buildnrunsettingspagewidget.h"
#include "../go_global.h"

namespace Go {
namespace Internal {

class GOSHARED_EXPORT BuildNRunSettingsPageWidget final : public QWidget {
    Q_OBJECT

public:
    explicit BuildNRunSettingsPageWidget();

private slots:
    void addTool();
    void cloneTool();
    void removeTool();
    void makeDefaultTool();
    void showDetails(const QModelIndex& index);

private:
    QStandardItem* autoDetectItem();
    QStandardItem* manualItem();

    Ui::BuildNRunSettingsPageWidget _ui;
    QStandardItemModel _model;
};

class GOSHARED_EXPORT BuildNRunSettingsPage final : public Core::IOptionsPage {
    Q_OBJECT

public:
    explicit BuildNRunSettingsPage(QWidget* parent = nullptr);

    QWidget* widget() override;
    void apply() override;
    void finish() override;

private:
    BuildNRunSettingsPageWidget* _widget = nullptr;
};

} // Internal
} // Go
