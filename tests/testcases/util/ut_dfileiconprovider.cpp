/*
* Copyright (C) 2021 ~ 2021 Uniontech Software Technology Co.,Ltd.
*
* Author:     Ye ShanShan <yeshanshan@uniontech.com>
*
* Maintainer: Ye ShanShan <yeshanshan@uniontech.com>>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <gtest/gtest.h>

#include "dfileiconprovider.h"
DWIDGET_USE_NAMESPACE
class ut_DFileIconProvider : public testing::Test
{
protected:
    void SetUp() override
    {
        target = DFileIconProvider::globalProvider();
    }
    void TearDown() override
    {
    }
    DFileIconProvider *target = nullptr;
};

TEST_F(ut_DFileIconProvider, globalProvider)
{
    target->globalProvider();
};

TEST_F(ut_DFileIconProvider, icon)
{
    QFileInfo file("/noexistent");
    QIcon icon = target->icon(file, QIcon::fromTheme("preferences-system"));
    ASSERT_EQ(icon.name(), QIcon::fromTheme("preferences-system").name());
};
