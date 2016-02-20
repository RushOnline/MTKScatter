#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>

#include "mtkscatter.h"

namespace Ui {
class MainWindow;
}

/*
class ScatterModel : public QAbstractItemModel
{
    Q_OBJECT
public:

    enum PartitionRoles {
        NameRole = Qt::UserRole + 1,
        SizeRole
    };

    ScatterModel(QObject *parent = 0);

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    bool loadFromFile(const QString& filename);

private:
    MTKScatter scatter;
};
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
