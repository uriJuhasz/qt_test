//============================================================================
// Name        : qt_test.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <QtCore/QDirIterator>
#include <QtCore/QtDebug>

using namespace std;

void test();
int main() {
	cout << "Start" << endl; // prints Start
	test();
	cout << "End" << endl; // prints Start
	return 0;
}

const string rootDir = "/home/uri";


void testR(QDir dir, int indents);
void test(){
	testR(QDir(QString::fromStdString(rootDir)),0);
}
void testR(QDir dir, int indents){

	string indentS(indents,' ');
	cout << indentS << "Opening \"" << dir.canonicalPath().toUtf8().constData() << "\"" << endl;
	QDirIterator it("/etc", QDirIterator::NoIteratorFlags);//Subdirectories);
	vector<QDir> subDirs;
	while (it.hasNext()) {
		it.next();
		auto isDir = it.fileInfo().isDir();
		auto isFile = it.fileInfo().isFile();
		if (isDir)
			subDirs.push_back(it.filePath());
//		auto cl = isDir ? "D" : isFile ? "F" : "?";
//		cout << "  [" << cl << "]" << string(it.fileName().toUtf8().constData()) << endl;
	    it.next();
	}
	for (auto sd : subDirs)
		testR(sd,indents+1);
}
