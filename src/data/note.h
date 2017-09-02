#pragma once
#ifndef CORBEAU_DATA_NOTE_H_
#define CORBEAU_DATA_NOTE_H_

#include <QObject>
#include <QString>

namespace corbeau {
namespace data {

class Note : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString name READ name WRITE setName NOTIFY nameChanged )
public:
    explicit Note( QObject* parent = nullptr );
    Note( const QString& name, QObject* parent = nullptr );

    QString name() const;

signals:
    void nameChanged( QString name );

public slots:
    void setName( QString name );

private:
    QString m_Name;
};

} // namespace data
} // namespace corbeau

#endif // CORBEAU_DATA_NOTE_H_
