#include <QDebug>

#include "mtkpartition.h"

MTKPartition::MTKPartition(QObject *parent) :
    QObject(parent)
{
}

/*
    partition_index: SYS0
    partition_name: preloader
    file_name: preloader_vanzo6752_lwt_kk.bin
    is_download: true
    type: SV5_BL_BIN
    linear_start_addr: 0x0
    physical_start_addr: 0x0
    partition_size: 0x40000
    region: EMMC_BOOT_1
    storage: HW_STORAGE_EMMC
    boundary_check: true
    is_reserved: false
    operation_type: BOOTLOADERS
    reserve: 0x00
*/
bool MTKPartition::loadFromNode(const YAML::Node &node)
{
    //qDebug() << QString::fromStdString(node.Scalar());
    Q_ASSERT(node.IsMap());

    for (auto it = node.begin(); it != node.end(); ++it) {
        auto key = it->first.Scalar().c_str();
        auto value = QString::fromStdString(it->second.Scalar());

        Q_ASSERT(property(key).toString().isEmpty());
        setProperty(key, value);
    }


    qDebug() << QString("partition_index     = %1").arg(partition_index());
    qDebug() << QString("partition_name      = %1").arg(partition_name());
    qDebug() << QString("file_name           = %1").arg(file_name());
    qDebug() << QString("is_download         = %1").arg(is_download());
    qDebug() << QString("type                = %1").arg(type());
    qDebug() << QString("linear_start_addr   = %1").arg(QString::number(linear_start_addr(), 16));
    qDebug() << QString("physical_start_addr = %1").arg(QString::number(physical_start_addr(), 16));
    qDebug() << QString("partition_size      = %1").arg(QString::number(partition_size(), 16));
    qDebug() << QString("region              = %1").arg(region());
    qDebug() << QString("storage             = %1").arg(storage());
    qDebug() << QString("boundary_check      = %1").arg(boundary_check());
    qDebug() << QString("is_reserved         = %1").arg(is_reserved());
    qDebug() << QString("operation_type      = %1").arg(operation_type());
    qDebug() << QString("reserve             = %1").arg(QString::number(reserve(), 16));

    return true;
}
