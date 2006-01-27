CVS_CHECKOUT = bub-n-bros
VERSION = 1.5
DISTFILES = bubbros-$(VERSION)-clientonly.tar.gz bubbros-$(VERSION)-win-clientonly.zip bubbros-$(VERSION)-win.zip bubbros-$(VERSION).tar.gz bubbros-$(VERSION).tar.bz2

PYTHONSOURCE = /usr/local/lib/python2.3/
PYTHONLIBFILES = BaseHTTPServer.py ConfigParser.py SimpleHTTPServer.py SocketServer.py StringIO.py UserDict.py __future__.py atexit.py base64.py bdb.py cgi.py chunk.py cmd.py colorsys.py copy.py copy_reg.py dummy_thread.py fnmatch.py ftplib.py getopt.py getpass.py glob.py gopherlib.py gzip.py htmlentitydefs.py httplib.py linecache.py macpath.py macurl2path.py mimetools.py mimetypes.py new.py ntpath.py nturl2path.py os.py os2emxpath.py pdb.py popen2.py posixpath.py pprint.py profile.py pstats.py py_compile.py quopri.py random.py re.py repr.py rfc822.py shutil.py site.py socket.py sre.py sre_compile.py sre_constants.py sre_parse.py stat.py string.py tempfile.py threading.py traceback.py types.py urllib.py urlparse.py uu.py warnings.py wave.py weakref.py webbrowser.py zipfile.py


all: export htmlpages dist

FORCE:

clean: rmtmpfiles
	rm -fr $(CVS_CHECKOUT)
	rm -f $(DISTFILES)

rmtmpfiles: FORCE
	rm -fr bubbros-$(VERSION)
	rm -f bubbros-$(VERSION).tar bubbros-$(VERSION)-clientonly.tar
	rm -fr winzip

export: clean
	cvs -z6 -d:ext:arigo@cvs.sourceforge.net:/cvsroot/bub-n-bros co -P bub-n-bros
	rm -r `find $(CVS_CHECKOUT) -name CVS`
	rm -r `find $(CVS_CHECKOUT) -name .cvsignore`
#	(cd $(CVS_CHECKOUT)/bubbob/images && python buildcolors.py -c)

htmlpages: FORCE $(CVS_CHECKOUT)/doc/crazybonuses.html $(CVS_CHECKOUT)/doc/sshots.html
	cp ../site/howto.html $(CVS_CHECKOUT)/doc/Introduction.html
	cp ../site/download.html $(CVS_CHECKOUT)/doc/
	cp ../site/help.html $(CVS_CHECKOUT)/doc/
	cp ../site/authors.html $(CVS_CHECKOUT)/doc/

$(CVS_CHECKOUT)/doc/%.html: FORCE
	echo "<html><head><title>sshots</title></head>" > $@
	echo "<body>This page is not included in the distribution." >> $@
	echo "You can <a href='http://bub-n-bros.sourceforge.net/$*.html'>find it on-line</a>." >> $@
	echo "</body></html>" >> $@

dist: $(DISTFILES)
	make rmtmpfiles

rmdist: FORCE
	rm -f $(DISTFILES)

%.gz: %
	cat $< | gzip -9 > $@

%.bz2: %
	cat $< | bzip2 > $@

bubbros-$(VERSION).tar bubbros-$(VERSION)-clientonly.tar:
	rm -fr bubbros-$(VERSION)
	cp -r $(CVS_CHECKOUT) bubbros-$(VERSION)
	tar cf bubbros-$(VERSION).tar bubbros-$(VERSION)
	rm -r bubbros-$(VERSION)/bubbob
	rm -r bubbros-$(VERSION)/java
	tar cf bubbros-$(VERSION)-clientonly.tar bubbros-$(VERSION)
	rm -r bubbros-$(VERSION)

bubbros-$(VERSION)-win.zip bubbros-$(VERSION)-win-clientonly.zip:
	rm -fr winzip
	cp -r $(CVS_CHECKOUT) winzip
	rm -f winzip/BubBob.icns
	cp ../Windows/BubBob.exe winzip/
	cp ../Windows/statesaver23.pyd winzip/bubbob/statesaver.pyd
	cp ../Windows/wingame23.pyd winzip/display/wingame.pyd
	mkdir winzip/DLLs
	(cd winzip/DLLs && unzip ../../../Windows/PythonBinaries.zip)
	mv winzip/DLLs/python23.dll winzip/
	mkdir winzip/Lib
	cp $(addprefix $(PYTHONSOURCE),$(PYTHONLIBFILES)) winzip/Lib/
	echo "#empty" > winzip/Lib/site.py
	python unix2win.py `find winzip -name "*.txt"`
	python unix2win.py `find winzip -name "*.py"`
	python unix2win.py `find winzip -name "*.html"`
	python unix2win.py `find winzip -name "*.java"`
	python unix2win.py `find winzip -name "*.c"`
	python unix2win.py winzip/bubbob/levels/rnglevel
	(cd winzip && zip -r -9 ../bubbros-$(VERSION)-win.zip *)
	rm -r winzip/bubbob
	rm -r winzip/java
	(cd winzip && zip -r -9 ../bubbros-$(VERSION)-win-clientonly.zip *)
	rm -r winzip
