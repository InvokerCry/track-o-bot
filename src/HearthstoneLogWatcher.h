#pragma once

#include <QString>
#include <QTimer>

class HearthstoneLogWatcher : public QObject
{
  Q_OBJECT

private:
  QString mId;
  QString mPath;
  qint64 mLastSeekPos;
  QTimer mTimer;

public:
  HearthstoneLogWatcher( QObject *parent, const QString& id, const QString& path );

private slots:
  void CheckForLogChanges();

  void HandleGameStart();
  void HandleGameStop();

signals:
  void LineAdded( const QString& id, const QString& line );

};
