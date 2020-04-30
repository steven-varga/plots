all:
	mkdocs build

upload: all
	rsync -az  site/ osaka:plot/

dot: docs/dot/type.dot
	dot -Tsvg docs/dot/type.dot -o docs/pix/meta.svg

view:
	xdg-open  http://127.0.0.1:8000
	mkdocs serve

clean:
	$(RM) -rf site



