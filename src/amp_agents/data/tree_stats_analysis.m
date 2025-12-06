clear;
close all;

load("tree_stats.csv")

nodes = tree_stats(:,1);
dist_dev = tree_stats(:,2);
coverage = tree_stats(:,3);
end_velocity = tree_stats(:,4);
time_to_propagate = tree_stats(:,5);


figure(1)
hold on
plot(time_to_propagate, coverage * 100)
hold off
title("Workspace Coverage Vs Propagtion Time")
xlabel("Time to Propagate (s)");
ylabel("Coverage (%)");

figure(2)
hold on;
plot(nodes, end_velocity, "b-")
plot([887], [.1571], "rx")
hold off;
title("Average End Velocity Vs Number of Nodes")
xlabel("Leaf Nodes");
ylabel("Average End Velocity");
legend("Initial Propagation Only", "After Second Propagation")

figure(3)
plot(time_to_propagate, nodes)
title("Propagation Time Vs Leaf Nodes")
xlabel("Time to Propagate (s)");
ylabel("Leaf Nodes");

figure(4)
plot(nodes, dist_dev)
title("Leaf Nodes vs Average Distance Factor")
xlabel("Leaf Nodes");
ylabel("Distance Deviation Factor");(5 + sqrt(2) * .6)^2