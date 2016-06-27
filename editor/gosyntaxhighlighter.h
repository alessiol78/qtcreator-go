#pragma once

#include <texteditor/textdocumentlayout.h>
#include <texteditor/syntaxhighlighter.h>

#include <QMap>

#include "../go_global.h"

namespace Go {

class Token;

class GOSHARED_EXPORT SyntaxHighlighter final : public TextEditor::SyntaxHighlighter
{
public:
    SyntaxHighlighter(QTextDocument* parent = 0);

protected:
    void highlightBlock(const QString& text) override;

private:
    int highlightLine(const QString& text, int state);
    QTextCharFormat formatForToken(const Token& token, const QString& val);

    static QMap<int, int> kCategories;
};

} // Go
