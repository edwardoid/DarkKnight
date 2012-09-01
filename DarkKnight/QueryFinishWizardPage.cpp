#include "QueryFinishWizardPage.h"
#include <Framework.h>
#include <DataStore.h>
#include <RootNode.h>
#include <QueryParser.h>

QueryFinishWizardPage::QueryFinishWizardPage(QWidget *parent)
	: QWizardPage(parent)
{
	ui.setupUi(this);
}

QueryFinishWizardPage::~QueryFinishWizardPage()
{

}

void QueryFinishWizardPage::initializePage()
{
	ui.progressBar->setValue(0);
	Framework* fw = framework();
	setCurrentAction(tr("Collecting information..."));
	quint32 storeId = field("store").value<quint32>();
	const QString queryStr = field("query").toString();
	setCurrentAction(tr("Looking for store..."));
	const DataStore* dataStore = fw->dataStoreById(storeId);
	if(dataStore == NULL) return;
	setCurrentAction(tr("Store found..."));
	setCurrentAction(tr("Parsing query..."));
	CGSQL_NS::RootNode *root = CGSQL_NS::QueryParser::parse(queryStr.toStdString());
	if (root == NULL)
	{
		setCurrentAction("Error while parting query.");
		exit(-1);
	}
	pgn::GameCollection loadedGames;
	setCurrentAction(tr("Retrieving games from %1...").arg(dataStore->name().toLower()));
	bool loadResult = dataStore->load(root, loadedGames);
	if(!loadResult)
	{
		setCurrentAction(tr("Can not load games from %1...").arg(dataStore->name().toLower()));
		exit(-1);
	}
	setCurrentAction(tr("Loaded %1 games. Looking for concepts in its...").arg(loadedGames.size()));
	ui.progressBar->setValue(100);
}

bool QueryFinishWizardPage::isComplete() const
{
	return true;
}
