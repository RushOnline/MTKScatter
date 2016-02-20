#include "mtkscatter.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->partitionsTree->setColumnCount(3);
    ui->partitionsTree->setHeaderLabels(QStringList() << "Partition" << "Key" << "Value" );

    MTKScatter scatter;
    Q_ASSERT(scatter.loadFromFile("/home/rush/opt/Hammer/MP_mt6732_m316b_blueplus_nyx_cc_128-16_kk_lte_3m-fdd-cs_mul_sw_20150530-133115_songlixin_PC/MT6752_Android_scatter.txt"));

    foreach(MTKPartition::Pointer partition, scatter.partitions) {
        if (!partition) continue;

        QTreeWidgetItem* node = new QTreeWidgetItem(ui->partitionsTree, QStringList(partition->partition_name()));
        ui->partitionsTree->addTopLevelItem(node);
        foreach(QByteArray key, partition->dynamicPropertyNames()) {
            QTreeWidgetItem* pair = new QTreeWidgetItem(node, QStringList() << "" << QString(key) << partition->property(key.data()).toString() );
        }

        //QTreeWidgetItem* pair = new QTreeWidgetItem(node, QStringList() <<  );

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*

ScatterModel::ScatterModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SizeRole] = "size";
    setRoleNames(roles);
}

QModelIndex ScatterModel::index(int row, int column, const QModelIndex &parent) const
{
    return QModelIndex();
}

QModelIndex ScatterModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int ScatterModel::rowCount(const QModelIndex &parent) const
{
    return 1;
}

int ScatterModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ScatterModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

bool ScatterModel::loadFromFile(const QString &filename)
{
    bool result = false;
    if (scatter.loadFromFile("/home/rush/opt/Hammer/MP_mt6732_m316b_blueplus_nyx_cc_128-16_kk_lte_3m-fdd-cs_mul_sw_20150530-133115_songlixin_PC/MT6752_Android_scatter.txt")) {
        //emit dataChanged( QModelIndex(0, 0, this), QModelIndex(0, 0, this));
    }
    return result;
}

*/

