import os
import subprocess
import requests
import http.server
import socketserver
from pathlib import Path

def analyze():
    # Step 1: Run ruff and get output
    ruff_output = subprocess.run(["ruff", "--format=json", "./"], 
                                 capture_output=True, text=True).stdout

    # Step 2: Fetch HTML from external URL
    res = requests.get("https://akx.github.io/ruff-report")
    html_content = res.text

    # Step 3: Create JS code with embedded JSON
    js_code = f"""
    <script type="text/javascript">
        const json_str = "{ruff_output}";

        const fillAndClick = () => {
            const textarea = document.querySelector("textarea.mantine-JsonInput-input");
            const button = document.querySelector("button[data-button=true]");

            if (textarea && button) {
                textarea.value = json_str;
                button.click();
            }
        };

        const interval = setInterval(fillAndClick, 1000);
    </script>
    """

    # Step 4: Insert JS into HTML
    new_html = html_content.replace("</body>", f"{js_code}</body>")

    # Step 5: Ensure "analysis" folder exists and save new HTML
    analysis_path = Path("reports/analysis")
    analysis_path.mkdir(parents=True, exist_ok=True)

    with open(analysis_path / "index.html", "w") as f:
        f.write(new_html)

    # Step 6: Start HTTP server
    os.chdir(analysis_path)
    PORT = 8000
    Handler = http.server.SimpleHTTPRequestHandler
    httpd = socketserver.TCPServer(("", PORT), Handler)
    print(f"Serving at port {PORT}. Navigate to http://localhost:{PORT}")
    httpd.serve_forever()

if __name__ == "__main__":
    analyze()
