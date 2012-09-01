#ifndef QUERYFINISHWIZARDPAGE_H
#define QUERYFINISHWIZARDPAGE_H

#include <QWizardPage>
#include "ui_QueryFinishWizardPage.h"
#include <CalculationResultForGame.h>
#include <FrameworkUser.h>

class QueryFinishWizardPage : public QWizardPage, public FrameworkUser
{
	Q_OBJECT

public:
	QueryFinishWizardPage(QWidget *parent = 0);
	~QueryFinishWizardPage();
	inline CalculationResultForGame result() const { return m_calcResult; }
	void initializePage();
	bool isComplete() const;
private:
	inline void setCurrentAction(const QString& text) { ui.currActionLabel->setText(text); }
private:
	Ui::QueryFinishWizardPage ui;
	CalculationResultForGame m_calcResult;
};

#endif // QUERYFINISHWIZARDPAGE_H
