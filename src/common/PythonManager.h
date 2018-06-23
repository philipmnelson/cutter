#ifndef PYTHONMANAGER_H
#define PYTHONMANAGER_H

#include <QObject>

class CutterPythonPlugin;
typedef struct _ts PyThreadState;
typedef struct _object PyObject;

class PythonManager : public QObject
{
    Q_OBJECT

public:
    static PythonManager *getInstance();

    PythonManager();
    ~PythonManager();

    void setPythonHome(const QString pythonHome)
    {
        customPythonHome = pythonHome;
    }

    void initPythonHome();
    void initialize();
    void addPythonPath(char *path);

    bool startJupyterNotebook();
    QString getJupyterUrl();

    CutterPythonPlugin *loadPlugin(char *pluginName);

    PyObject *getAttrStringSafe(PyObject *object, const char* attribute);

private:
    QString customPythonHome;
    wchar_t *pythonHome = nullptr;
    PyThreadState *pyThreadState = nullptr;

    PyObject *cutterJupyterModule;
    PyObject *cutterPluginModule;
    PyObject *cutterNotebookAppInstance = nullptr;
};

#define Python() (PythonManager::getInstance())

#endif // PYTHONMANAGER_H
