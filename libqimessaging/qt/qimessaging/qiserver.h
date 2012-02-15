/*
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2012 Aldebaran Robotics
*/

#ifndef   	QT_QISERVER_H_
# define   	QT_QISERVER_H_

#include <QtCore/QObject>
#include <qimessaging/qisession.h>

class QiServerPrivate;
class NetworkThread;

class QiServer {
public:
  QiServer();
  ~QiServer();

  void start(const QString &addr, unsigned short port, QiSession *session);

  void advertiseService(const QString &name, QObject *obj);

protected:
  QiServerPrivate *_p;
};


#endif 	    /* !QISERVER_H_ */
