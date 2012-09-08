#ifndef QUERYFINISHWIZARDPAGE_H
#define QUERYFINISHWIZARDPAGE_H

#include <QWizardPage>
#include "ui_QueryFinishWizardPage.h"
#include "QueryResult.h"
#include <FrameworkUser.h>

class QueryFinishWizardPage : public QWizardPage, public FrameworkUser
{
	Q_OBJECT

public:
	explicit QueryFinishWizardPage(QWidget *parent = 0);
	~QueryFinishWizardPage();
	inline void setResultData(QueryResult* result) { m_result = result; ASSERT(result != NULL); }
	void initializePage();
	bool isComplete() const;
private:
	inline void setCurrentAction(const QString& text) { ui.currActionLabel->setText(text); }
private:
	Ui::QueryFinishWizardPage ui;
	QueryResult* m_result;
};

#endif // QUERYFINISHWIZARDPAGE_H
