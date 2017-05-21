#pragma once

#include <texteditor/syntaxhighlighter.h>
#include <texteditor/textdocumentlayout.h>

#include <QMap>

#include "../go_global.h"

namespace Go {
namespace Internal {

class Token;

class GOSHARED_EXPORT SyntaxHighlighter final : public TextEditor::SyntaxHighlighter
{
public:
    SyntaxHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) override;

private:
    int highlightLine(const QString &text, int state);
    QTextCharFormat formatForToken(const Token &token, const QString &val);

    static QMap<int, int> kCategories;
};

} // namespace Internal
} // namespace Go
