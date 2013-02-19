#include "QueryWizard.h"
#include "ApplicationConstants.h"
#include "StoreChooseWizardPage.h"
#include "AdvancedQueryPage.h"
#include "QueryFinishWizardPage.h"
#include <QMessageBox>
#include <Framework.h>
#include <Settings.h>
#include <DataStore.h>

QueryWizard::QueryWizard(QueryResult* result, QWidget* parent /* = NULL */)
	: QWizard(parent)
{
	initWithFramework(Framework::instance());
	setWindowTitle("Query Wizard");
	addPages(result);
// 	ui->chooseStorePage->initWithFramework(fw);
// 	ui->finalPage->initWithFramework(fw);
// 	ui->finalPage->setResultData(result);
}


QueryWizard::~QueryWizard(void)
{
}

void QueryWizard::addPages(QueryResult* data)
{
	ASSERT(data != NULL);
	StoreChooseWizardPage* storeChoosePage = new StoreChooseWizardPage(this);
	storeChoosePage->initWithFramework(framework());
	addPage(storeChoosePage);

	Settings* settings = framework()->settings();
	QVariant mode = settings->get(APP_SETTINGS, APP_QUERY_MODE, APP_QUERY_MODE_BUILDER);
	if(mode.toString() != APP_QUERY_MODE_PLAIN_QUERY)
		addPage(new AdvancedQueryPage(this));
	else
		addPage(new AdvancedQueryPage(this));
	QueryFinishWizardPage* finishPage = new QueryFinishWizardPage(this);
	finishPage->initWithFramework(framework());
	finishPage->setResultData(data);
	addPage(finishPage);
}
