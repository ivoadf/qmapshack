/**********************************************************************************************
    Copyright (C) 2021 Oliver Eichler <oliver.eichler@gmx.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

**********************************************************************************************/

#ifndef CTRYMUTEXLOCKER_H
#define CTRYMUTEXLOCKER_H

#include <QMutex>

class CTryMutexLocker
{
public:
    CTryMutexLocker(QMutex& mutex) : m_mutex(mutex){}
    ~CTryMutexLocker()
    {
        if(needsUnlock)
        {
            m_mutex.unlock();
        }
    }
    bool try_lock()
    {
        needsUnlock = m_mutex.tryLock();
        return needsUnlock;
    }
private:
    QMutex& m_mutex;
    bool needsUnlock {false};
};

#endif //CTRYMUTEXLOCKER_H

