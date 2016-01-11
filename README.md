# qml_viewmodels_concept
C++ ViewModel implementation for QML views

The main purpose of this project is to test a way to interface the C++ layer of the application with the QML layer using only a minimal amount of QML/JS.

The architecture is someway inspired by the MVVM pattern used in WPF/.NET applications.

A framework is provided to implement C++ ViewModel classes with rich properties (field backends) that can be connected declaratively to subclassed QML components using only data bindings.

Every change in the QML UI status is notified to the C++ ViewModel `do_updateView` function, which can react manipulating properties of the field backends, which are propagated to the QML via data binding.

During the execution of `do_updateView` all the applied changes are cached and applied at once at the end, to avoid flickering on the UI.

Another concept demonstrated is the ability to show at startup distinct QML subtrees implementing potentially completely different UIs that share the same C++ code. In the example there are four different UIs and the user is prompted to select one of them, but in a real application the choice may be done programmatically at run time or at build time.

This can be useful to implement GUIs for different platforms/form factors reusing the core of the application with a minimal effort needed just to code the different QML layouts.
