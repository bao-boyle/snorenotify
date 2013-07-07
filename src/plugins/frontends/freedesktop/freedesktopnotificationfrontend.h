/*
    SnoreNotify is a Notification Framework based on Qt
    Copyright (C) 2013  Patrick von Reth <vonreth@kde.org>


    SnoreNotify is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SnoreNotify is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with SnoreNotify.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FREEDESKTOPNOTIFICATION_FRONTEND_H
#define FREEDESKTOPNOTIFICATION_FRONTEND_H
#include "core/plugins/snorefrontend.h"
#include <QtDBus>

class FreedesktopFrontend:public Snore::SnoreFrontend{
    Q_OBJECT
    Q_INTERFACES(Snore::SnoreFrontend)
public:
    FreedesktopFrontend();
    ~FreedesktopFrontend();
    virtual bool init(Snore::SnoreCore *snore);

    void actionInvoked(Snore::Notification notification);
    void notificationClosed(Snore::Notification notification);
    uint Notify(const QString &app_name, uint replaces_id, const QString &app_icon, const QString &summary, const QString &body, const QStringList &actions, const QVariantMap &hints, int timeout);
    void CloseNotification( uint id );

    QStringList GetCapabilities();
    QString GetServerInformation(QString& vendor, QString& version, QString& specVersion);	

signals:
    void NotificationClosed( uint id, uint reason );
    void ActionInvoked( uint id, const QString& actionKey );


};

#endif//FREEDESKTOPNOTIFICATION_FRONTEND_H
