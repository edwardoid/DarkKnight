#ifndef FRAMEWORKUSER_H
#define FRAMEWORKUSER_H

class Framework;

class FrameworkUser
{
public:
    FrameworkUser();
    virtual void initWithFramework(Framework* fw);
    virtual Framework* framework() const;
private:
    Framework* m_framework;
};

#endif // FRAMEWORKUSER_H
