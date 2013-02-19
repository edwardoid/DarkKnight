#ifndef CGSQL_HIGHLIGHTRER_H
#define CGSQL_HIGHLIGHTRER_H

#include <QSyntaxHighlighter>

class CGSQLSyntaxHighlighter :
	public QSyntaxHighlighter
{
	Q_OBJECT
public:
	CGSQLSyntaxHighlighter(QObject* parent = 0);
	virtual ~CGSQLSyntaxHighlighter();
protected:
	void highlightBlock(const QString & text);
private:
	struct Rule
	{
		QRegExp exp;
		QTextCharFormat format;
	};
private:
	void initKeywords();
	void initConcepts();
private:;
	Rule m_keywordRule;
};

#endif // CGSQL_HIGHLIGHTRER_H