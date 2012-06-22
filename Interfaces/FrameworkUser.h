#ifndef FRAMEWORKUSER_H
#define FRAMEWORKUSER_H

class Framework;

class FrameworkUser
{
public:
    FrameworkUser();
    void initWithFramework(Framework* fw);
    Framework* framework();
private:
    Framework* m_framework;
};

#endif // FRAMEWORKUSER_H
