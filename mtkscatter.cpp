#include <QDebug>

#include "qtyaml.h"
#include "mtkscatter.h"

MTKScatter::MTKScatter(QObject *parent) :
    QObject(parent),
    partitions(30)
{
}

bool MTKScatter::loadFromFile(const QString &filename)
{
    YAML::Node root = YAML::LoadFile(filename.toStdString());
    return loadFromNode(root);
}

bool MTKScatter::loadFromNode(const YAML::Node &root)
{
    Q_ASSERT(root.IsSequence());
    qDebug() << QString::fromStdString(root.Scalar()) << " Type: " << root.Type() << "Size: " << root.size();
    for (auto it = root.begin(); it != root.end(); ++it) {
        const YAML::Node & node = *it;
        Q_ASSERT(node.IsMap());

        if (node["partition_index"]) {
            qDebug() << "* partition " << QString::fromStdString(node["partition_index"].Scalar());

            MTKPartition::Pointer partition = new MTKPartition;
            Q_ASSERT(partition);

            Q_ASSERT(partition->loadFromNode(node));

            partitions[ partition->partition_index() ] = partition;

        } else if (node["general"] && node["info"]) {
            Q_ASSERT(QString::fromStdString(node["general"].Scalar()) == "MTK_PLATFORM_CFG" );
            Q_ASSERT(node["info"].IsSequence());
            Q_ASSERT(node["info"].size() == 1);
            const YAML::Node & info = node["info"][0];
            Q_ASSERT(info.IsMap());

            /*
            config_version: V1.1.2
            platform: MT6752
            project: vanzo6752_lwt_kk
            storage: EMMC
            boot_channel: MSDC_0
            block_size: 0x20000
             */

            qDebug() << "* found config" << QString::fromStdString(info["config_version"].Scalar());
        }

    }
    return true;
}
