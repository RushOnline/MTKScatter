#ifndef MTKPARTITION_H
#define MTKPARTITION_H

#include <QObject>
#include <QPointer>
#include <QVariant>

#include <yaml-cpp/yaml.h>

class MTKPartition : public QObject
{
    Q_OBJECT
public:
    typedef QPointer<MTKPartition> Pointer;


    explicit MTKPartition(QObject *parent = 0);

    bool loadFromNode(const YAML::Node &node);

    int partition_index() const {
        return property("partition_index").toString().mid(3).toInt();
    }

    const QString partition_name() const {
        return property("partition_name").toString();
    }

    const QString file_name() const {
        return property("file_name").toString();
    }

    bool is_download() const {
        return (property("is_download").toString() == "true");
    }

    const QString type() const {
        return property("type").toString();
    }

    quint64 linear_start_addr() const {
        return property("linear_start_addr").toString().mid(2).toInt(0, 16);
    }

    quint64 physical_start_addr() const {
        return property("physical_start_addr").toString().mid(2).toInt(0, 16);
    }

    quint64 partition_size() const {
        return property("partition_size").toString().mid(2).toInt(0, 16);
    }

    quint64 reserve() const {
        return property("reserve").toString().mid(2).toInt(0, 16);
    }

    const QString region() const {
        return property("region").toString();
    }

    const QString storage() const {
        return property("storage").toString();
    }

    bool boundary_check() const {
        return (property("boundary_check").toString() == "true");
    }

    bool is_reserved() const {
        return (property("is_reserved").toString() == "true");
    }

    const QString operation_type() const {
        return property("operation_type").toString();
    }

signals:

public slots:

};

#endif // MTKPARTITION_H
