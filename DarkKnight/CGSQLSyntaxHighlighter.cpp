#include "CGSQLSyntaxHighLighter.h"
#include <Keywords.h>

CGSQLSyntaxHighlighter::CGSQLSyntaxHighlighter(QObject* parent)
	: QSyntaxHighlighter(parent)
{
}


CGSQLSyntaxHighlighter::~CGSQLSyntaxHighlighter()
{
	/*
#define CONCEPT_DELIMETER "."
#define HEADER_BEGIN      '['
#define HEADER_END        ']'
#define BEGIN             '('
#define END               ')'
#define PLAYER_NAME_QTT   '"'
#define AND_K             "AND"
#define OR_K              "OR"
#define XOR_K             "XOR"
#define COMMENT           '#' */
}

void CGSQLSyntaxHighlighter::initKeywords()
{
	m_keywordRule.format.setForeground(Qt::darkBlue);
	m_keywordRule.format.setFontWeight(QFont::Bold);
	QStringList keywordPatterns;
	keywordPatterns << WHITES << QString(WHITES).toLower()
					<< BLACKS << QString(BLACKS).toLower()
					<< WINS << QString(WINS).toLower()
					<< TIE << QString(TIE).toLower()
					<< HAS << QString(HAS).toLower()
					<< HASNT << QString(HASNT).toLower()
					<< AND_K << QString(AND_K).toLower()
					<< OR_K << QString(OR_K).toLower()
	foreach (const QString &pattern, keywordPatterns) {
		m_keywordRule.pattern = QRegExp(pattern);
		m_keywordRule.format = keywordFormat;
		highlightingRules.append(rule);
	}

	classFormat.setFontWeight(QFont::Bold);
	classFormat.setForeground(Qt::darkMagenta);
	rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
	rule.format = classFormat;
	highlightingRules.append(rule);

	singleLineCommentFormat.setForeground(Qt::red);
	rule.pattern = QRegExp("//[^\n]*");
	rule.format = singleLineCommentFormat;
	highlightingRules.append(rule);

	multiLineCommentFormat.setForeground(Qt::red);

	quotationFormat.setForeground(Qt::darkGreen);
	rule.pattern = QRegExp("\".*\"");
	rule.format = quotationFormat;
	highlightingRules.append(rule);

	functionFormat.setFontItalic(true);
	functionFormat.setForeground(Qt::blue);
	rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
	rule.format = functionFormat;
	highlightingRules.append(rule);

	commentStartExpression = QRegExp("/\\*");
	commentEndExpression = QRegExp("\\*/");
}

bool CGSQLSyntaxHighlighter::highlightKeyword( const QString& keyword )
{
	return false;
}

bool CGSQLSyntaxHighlighter::highlightComment( const QString& comment )
{
	return false;
}

void CGSQLSyntaxHighlighter::highlightBlock( const QString & text )
{
	if(highlightKeyword(text)) return;
	if(highlightComment(text)) return;
	if(highlightComment(text)) return;
}
