# libcurl-httpbin-testsuite
[![Build Status](https://travis-ci.org/xquery/libcurl-httpbin-testsuite.svg?branch=master)](https://travis-ci.org/xquery/libcurl-httpbin-testsuite)

Test libcurl with httpbin

Note that this is a test only software library.

# Build

To build software, run cmake:

```$bash
> mkdir build
> cd build
> cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_MANUAL=OFF -DBUILD_TESTING=OFF  ..
> make 
```

# Setup and run Tests

Tests require [httpbin](http://httpbin.org) - which should be setup on port 81 - running the following docker command
or however way you feel comfortable installing.

```$bash
> docker run -p 81:80 kennethreitz/httpbin
```

Edit test/unit-test.h if you expose httpbin on a different host:port.

After building usually it is just a matter of running make test target.

```$bash
> make test
```

or you could run directly
```$bash
> cd test
> ./runAllTests
```

# FAQ

### Why test libcurl ? 
more tests better ;)

## Why use httpbin ? 
covers all http methods/behavior

### Why use googletest ? 
intersection with C/C++

## License

libcurl-httpbin-testsuite is provided under the [MIT License](COPYING)

MIT License

Copyright (c) 2017-2018 James Fuller <jim.fuller@webcomposite.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.