#ifndef QUERY_EDITOR_H
#define QUERY_EDITOR_H
#include <QDialog>

namespace Ui {
	class QueryEditor;
}

class QueryEditor: public QDialog
{
	Q_OBJECT
public:
	QueryEditor(QWidget* parent = NULL);
	virtual ~QueryEditor();
private:
	Ui::QueryEditor* ui;
};

#endif // QUERY_EDITOR_H