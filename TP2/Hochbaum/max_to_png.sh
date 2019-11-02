source_folder=/Users/Kevin/Documents/DL/AA/TP2/Hochbaum

for i in ./*.max; do
    (echo "digraph {";perl -ne 'if (/^a\s+(\d+)\s+(\d+)\s+(\d+)\s*$/){print qq{\t $1 -> $2 [label="$3"]\n};}' "$i" ; echo "}") > file.dot
    docker run -it -w /data --mount type=bind,source=$source_folder,target=/data risaacson/graphviz dot -Tpng /data/file.dot -o /data/$i.png
    rm file.dot
done
