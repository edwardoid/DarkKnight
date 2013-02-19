#ifndef ADVANCEDQUERYPAGE_H
#define ADVANCEDQUERYPAGE_H

#include <QWizardPage>
#include "ui_AdvancedQueryPage.h"

namespace Ui {
	class AdvancedQueryPage;
}

class AdvancedQueryPage : public QWizardPage
{
	Q_OBJECT

public:
	AdvancedQueryPage(QWidget *parent = 0);
	~AdvancedQueryPage();
public slots:
	virtual bool isComplete() const;
private slots:
	void loadFromFile();
private:
	Ui::AdvancedQueryPage* ui;
};

#endif // ADVANCEDQUERYPAGE_H
