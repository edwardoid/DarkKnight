#ifndef QUERYWIZARD_H
#define QUERYWIZARD_H

#include <QWizard>
#include "QueryResult.h"

class QListWidgetItem;

class QueryWizard :
	public QWizard,
	public FrameworkUser
{
	Q_OBJECT
public:
	explicit QueryWizard(QueryResult* data, QWidget* parent = NULL);
	virtual ~QueryWizard();
private:
	void addPages(QueryResult* data);
};

#endif // QUERYWIZARD_H