#ifndef QUERYEVALUATIONTHREAD_H
#define QUERYEVALUATIONTHREAD_H

#include <QThread>

class QueryEvaluationThread :
	public QThread
{
public:
	QueryEvaluationThread(void);
	virtual ~QueryEvaluationThread(void);
};

#endif // QUERYEVALUATIONTHREAD_H