# Build tex files into a PDF.
build:
    #!/bin/bash
    set -e
    # cd plantuml
    # plantuml *.puml
    # mv *.png ../assets/
    cd {{justfile_directory()}}/TP1
    pdflatex -shell-escape \\nonstopmode\\input Tp1-IriarteNicolas.tex || echo "First compilation failed."
    # pdflatex -shell-escape \\nonstopmode\\input Tp1-IriarteNicolas.tex || echo "Second compilation failed."
    # pdflatex -shell-escape \\nonstopmode\\input Tp1-IriarteNicolas.tex

    cd {{justfile_directory()}}/TP2
    cd plantuml

    plantuml *.puml
    mv *.png ../Figuras/

    cd ..
    pdflatex -shell-escape \\nonstopmode\\input Tp2-IriarteNicolas.tex || echo "First compilation failed."
    # pdflatex -shell-escape \\nonstopmode\\input Tp2-IriarteNicolas.tex || echo "Second compilation failed."
    # pdflatex -shell-escape \\nonstopmode\\input Tp2-IriarteNicolas.tex


# Clean repository.
clean:
    #!/bin/bash
    rm -rf */*.aux */*.log */*.out */*.toc */*.pdf
