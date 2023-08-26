import pytest
import http.server
import os

def test():
    # Run your unit tests with pytest
    pytest.main(["-x", "test/"])

    # Start an HTTP server to serve any reports or logs if needed
    PORT = 8000
    Handler = http.server.SimpleHTTPRequestHandler
    httpd = http.server.HTTPServer(("", PORT), Handler)
    print(f"Serving at port {PORT}. Navigate to http://localhost:{PORT}")
    httpd.serve_forever()

if __name__ == '__main__':
    test()
