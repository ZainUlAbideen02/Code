const canvas = document.getElementById("graphCanvas");
const ctx = canvas.getContext("2d");

// Node (city) structure
const nodes = [
  { id: "A", x: 150, y: 100 },
  { id: "B", x: 400, y: 80 },
  { id: "C", x: 650, y: 150 },
  { id: "D", x: 250, y: 350 },
  { id: "E", x: 500, y: 400 }
];

// Edges (roads between cities)
const edges = [
  ["A", "B"],
  ["B", "C"],
  ["A", "D"],
  ["D", "E"],
  ["C", "E"]
];

// Draw edges
function drawEdges() {
  ctx.strokeStyle = "#ffffff";
  ctx.lineWidth = 2;
  edges.forEach(([from, to]) => {
    const n1 = nodes.find(n => n.id === from);
    const n2 = nodes.find(n => n.id === to);
    ctx.beginPath();
    ctx.moveTo(n1.x, n1.y);
    ctx.lineTo(n2.x, n2.y);
    ctx.stroke();
  });
}

// Draw nodes
function drawNodes() {
  nodes.forEach(node => {
    ctx.beginPath();
    ctx.arc(node.x, node.y, 25, 0, Math.PI * 2);
    ctx.fillStyle = "#2196f3";
    ctx.fill();
    ctx.strokeStyle = "#00bcd4";
    ctx.lineWidth = 2;
    ctx.stroke();

    // Draw label
    ctx.fillStyle = "white";
    ctx.font = "18px Arial";
    ctx.textAlign = "center";
    ctx.fillText(node.id, node.x, node.y + 6);
  });
}

// Animation loop
function render() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  drawEdges();
  drawNodes();
  requestAnimationFrame(render);
}

render();
canvas.addEventListener("mousemove", (e) => {
  const rect = canvas.getBoundingClientRect();
  const mouseX = e.clientX - rect.left;
  const mouseY = e.clientY - rect.top;

  nodes.forEach(node => {
    const dx = node.x - mouseX;
    const dy = node.y - mouseY;
    const dist = Math.sqrt(dx * dx + dy * dy);
    if (dist < 25) {
      node.hover = true;
      node.color = "#f44336"; // red when hovered
    } else {
      node.hover = false;
      node.color = "#2196f3"; // blue otherwise
    }
  });
});

function drawNodes() {
  nodes.forEach(node => {
    ctx.beginPath();
    ctx.arc(node.x, node.y, 25, 0, Math.PI * 2);
    ctx.fillStyle = node.hover ? node.color : "#2196f3";
    ctx.fill();
    ctx.strokeStyle = "#00bcd4";
    ctx.lineWidth = 2;
    ctx.stroke();

    ctx.fillStyle = "white";
    ctx.font = "18px Arial";
    ctx.textAlign = "center";
    ctx.fillText(node.id, node.x, node.y + 6);
  });
}
