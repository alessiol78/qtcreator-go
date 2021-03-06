#pragma once

#include <texteditor/syntaxhighlighter.h>
#include <texteditor/textdocumentlayout.h>

#include <QMap>

#include "../go_global.h"

namespace Go {
namespace Internal {

class GoToken;

class GoSyntaxHighlighter : public TextEditor::SyntaxHighlighter
{
public:
    GoSyntaxHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) override;

private:
    int highlightLine(const QString &text, int state);
    QTextCharFormat formatForToken(const GoToken &token, const QString &val);
};

} // namespace Internal
} // namespace Go
