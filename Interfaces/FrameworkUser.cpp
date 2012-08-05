#include "FrameworkUser.h"
#include <Framework.h>

FrameworkUser::FrameworkUser()
    : m_framework(NULL)
{
}

void FrameworkUser::initWithFramework(Framework *fw)
{
    m_framework = fw;
}

Framework* FrameworkUser::framework() const
{
    return m_framework;
}