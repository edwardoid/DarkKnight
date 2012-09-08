#include "QueryWizard.h"
#include "ui_QueryWizard.h"
#include "AdvancedQueryPage.h"
#include <QMessageBox>
#include <Framework.h>
#include <DataStore.h>

QueryWizard::QueryWizard(QueryResult* result, QWidget* parent /* = NULL */)
	: QWizard(parent)
	, ui(new Ui::QueryWizard)
{
	ui->setupUi(this);
	Framework* fw = Framework::instance();
	ui->chooseStorePage->initWithFramework(fw);
	ui->finalPage->initWithFramework(fw);
	ui->finalPage->setResultData(result);
}


QueryWizard::~QueryWizard(void)
{
}


