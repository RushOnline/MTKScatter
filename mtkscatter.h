#ifndef MTKSCATTER_H
#define MTKSCATTER_H

#include <QObject>
#include <QVector>

#include <yaml-cpp/yaml.h>

#include "mtkpartition.h"

class MTKScatter : public QObject
{
    Q_OBJECT
public:
    typedef QVector<MTKPartition::Pointer> Partitions;

    explicit MTKScatter(QObject *parent = 0);

    bool loadFromNode(const YAML::Node& root);
    bool loadFromFile(const QString& filename);

    Partitions  partitions;

signals:

public slots:
};

#endif // MTKSCATTER_H
