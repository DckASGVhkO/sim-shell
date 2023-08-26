import coverage
import pytest
import http.server
import os

def cover():
    # Initialize coverage object with branch coverage
    cov = coverage.Coverage(branch=True)
    
    # Start coverage collection
    cov.start()

    # Run your tests with pytest
    pytest.main(["-x", "test/"])

    # Stop coverage collection
    cov.stop()
    
    # Save the collected coverage data
    cov.save()

    # Generate HTML report
    cov.html_report(directory="reports/coverage")

    # Change to the coverage directory
    os.chdir("reports/coverage")

    # Start an HTTP server
    PORT = 8000
    Handler = http.server.SimpleHTTPRequestHandler
    httpd = http.server.HTTPServer(("", PORT), Handler)
    print(f"Serving at port {PORT}. Navigate to http://localhost:{PORT}")
    httpd.serve_forever()

if __name__ == "__main__":
    cover()
