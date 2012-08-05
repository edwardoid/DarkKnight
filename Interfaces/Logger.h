#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
public:
    virtual void log(const QString& mess) = 0;
};

#endif // LOGGER_H
