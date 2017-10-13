#pragma once

#include <texteditor/indenter.h>

#include "../go_global.h"

namespace Go {
namespace Internal {

class GoIndenter : public TextEditor::Indenter
{
public:
    GoIndenter();

    bool isElectricCharacter(const QChar &ch) const override;
    int indentFor(const QTextBlock &block, const TextEditor::TabSettings &tabSettings) override;

protected:
    bool isElectricLine(const QString &previousLine) const;
    int indentDiff(const QString &previousLine, const TextEditor::TabSettings &tabSettings) const;
};

} // namespace Internal
} // namespace Go
