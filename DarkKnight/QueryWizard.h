#ifndef QUERYWIZARD_H
#define QUERYWIZARD_H

#include <QWizard>

namespace Ui {
	class QueryWizard;
}

class QListWidgetItem;

class QueryWizard :
	public QWizard
{
	Q_OBJECT
public:
	QueryWizard(QWidget* parent = NULL);
	virtual ~QueryWizard(void);
private:
	Ui::QueryWizard* ui;;
};

#endif // QUERYWIZARD_H