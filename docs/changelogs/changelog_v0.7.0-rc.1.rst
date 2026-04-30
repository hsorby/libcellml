libCellML v0.7.0-rc.1 Changelog
===============================

Analyser
--------

* Analyser: account for an underconstrained NLA system by `@agarny <https://github.com/agarny>`_ [`#1338 <https://github.com/cellml/libcellml/pull/1338>`_].

Bug
---

* Fix bug with litre units by `@hsorby <https://github.com/hsorby>`_ [`#1314 <https://github.com/cellml/libcellml/pull/1314>`_].

Documentation
-------------

* Fix warnings when building the documentation with Doxygen by `@hsorby <https://github.com/hsorby>`_ [`#1349 <https://github.com/cellml/libcellml/pull/1349>`_].
* Updating citation information for libCellML by `@nickerso <https://github.com/nickerso>`_ [`#1361 <https://github.com/cellml/libcellml/pull/1361>`_].

Generator
---------

* Generator profile: fix `computeComputedConstants()`'s signature by `@agarny <https://github.com/agarny>`_ [`#1364 <https://github.com/cellml/libcellml/pull/1364>`_].
* Add additional overloads to `Generator` class implementationCode and interfaceCode methods by `@hsorby <https://github.com/hsorby>`_ [`#1345 <https://github.com/cellml/libcellml/pull/1345>`_].
* Add a `GeneratorVariableTracker` class to manage un/tracked variables by `@agarny <https://github.com/agarny>`_ [`#1340 <https://github.com/cellml/libcellml/pull/1340>`_].
* Allow a constant, a computed constant, or a state variable (but not an algebraic variable) to be used as an initial value by `@agarny <https://github.com/agarny>`_ [`#1325 <https://github.com/cellml/libcellml/pull/1325>`_].
* Code generator: allow for variables to be tracked/untracked by `@agarny <https://github.com/agarny>`_ [`#1256 <https://github.com/cellml/libcellml/pull/1256>`_].
* Code generator: use different arrays for constants, computed constants, and algebraic variables by `@agarny <https://github.com/agarny>`_ [`#1247 <https://github.com/cellml/libcellml/pull/1247>`_].
* Syntax error in generated Python code by `@agarny <https://github.com/agarny>`_ [`#1334 <https://github.com/cellml/libcellml/pull/1334>`_].
* API: simplify/improve the API for external variables by `@agarny <https://github.com/agarny>`_ [`#1252 <https://github.com/cellml/libcellml/pull/1252>`_].

Infrastructure
--------------

* CI by `@agarny <https://github.com/agarny>`_ [`#1315 <https://github.com/cellml/libcellml/pull/1315>`_].

JavaScript bindings
-------------------

* JavaScript: account for the fact that our JavaScript bindings use a 32-bit address space by `@agarny <https://github.com/agarny>`_ [`#1384 <https://github.com/cellml/libcellml/pull/1384>`_].

Miscellaneous
-------------

* Remove all unnecessary headers as guided by Qt Creator on macOS by `@hsorby <https://github.com/hsorby>`_ [`#1346 <https://github.com/cellml/libcellml/pull/1346>`_].

Contributors
------------

.. image:: https://avatars.githubusercontent.com/u/602265?v=4
   :target: https://github.com/agarny
   :height: 32
   :width: 32
.. image:: https://avatars.githubusercontent.com/u/778048?v=4
   :target: https://github.com/hsorby
   :height: 32
   :width: 32
.. image:: https://avatars.githubusercontent.com/u/811244?v=4
   :target: https://github.com/nickerso
   :height: 32
   :width: 32
