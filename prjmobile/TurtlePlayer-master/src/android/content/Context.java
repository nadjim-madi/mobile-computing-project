package android.content;

import android.content.res.Resources;
import android.content.pm.PackageManager;
import android.os.Handler;
import android.view.LayoutInflater;

/**
 * Interface to global information about an application environment.
 */
public abstract class Context {
    public Context() {}

    // Access application resources
    public abstract Resources getResources();

    // Access package-specific application context
    public abstract Context getApplicationContext();

    // Access a system service
    public abstract Object getSystemService(String name);

    // Start an activity
    public abstract void startActivity(Intent intent);

    // Start a service
    public abstract ComponentName startService(Intent service);

    // Stop a service
    public abstract boolean stopService(Intent service);

    // Send a broadcast
    public abstract void sendBroadcast(Intent intent);

    // Register a receiver
    public abstract Intent registerReceiver(BroadcastReceiver receiver, IntentFilter filter);

    // Unregister a receiver
    public abstract void unregisterReceiver(BroadcastReceiver receiver);

    // Inflate a view layout
    public abstract LayoutInflater getSystemService();

    // Get a handler for the main thread
    public abstract Handler getMainLooper();

    // Other utility methods omitted for brevity
}
