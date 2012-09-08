#ifndef QUERYWIZARD_H
#define QUERYWIZARD_H

#include <QWizard>
#include "QueryResult.h"

namespace Ui {
	class QueryWizard;
}

class QListWidgetItem;

class QueryWizard :
	public QWizard
{
	Q_OBJECT
public:
	explicit QueryWizard(QueryResult* data, QWidget* parent = NULL);
	virtual ~QueryWizard(void);
private:
	Ui::QueryWizard* ui;;
};

#endif // QUERYWIZARD_H