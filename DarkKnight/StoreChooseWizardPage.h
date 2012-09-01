#ifndef STORECHOOSEWIZARDPAGE_H
#define STORECHOOSEWIZARDPAGE_H

#include <QWizardPage>
#include <FrameworkUser.h>
#include "ui_StoreChooseWizardPage.h"

class Framework;
class QListWidgetItem;

class StoreChooseWizardPage : public QWizardPage, public FrameworkUser
{
	Q_OBJECT
	Q_PROPERTY(quint32 currentStore READ currentStore)
public:
	StoreChooseWizardPage(QWidget *parent = 0);
	~StoreChooseWizardPage();
	virtual void initWithFramework(Framework* fw);
	quint32 currentStore() const;
signals:
	void storeChanged(quint32);
private slots:
	void currentStoreChanged(QListWidgetItem*, QListWidgetItem*);
private:
	void populateDataStores();
private:
	Ui::StoreChooseWizardPage ui;
	quint32 m_currentStore;
};

#endif // STORECHOOSEWIZARDPAGE_H
