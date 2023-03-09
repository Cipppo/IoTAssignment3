package com.example.room_mobile_app;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;

import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;

import android.view.View;

import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

import com.example.room_mobile_app.databinding.ActivityMainBinding;

import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private AppBarConfiguration appBarConfiguration;
    private ActivityMainBinding binding;


    private List<BluetoothDevice> scannedDevices = new ArrayList<>();
    private List<String> scannedNameList = new ArrayList<>();

    private List<BluetoothDevice> pairedDevices = new ArrayList<>();
    private List<String> pairedNameList = new ArrayList<>();
    private BluetoothAdapter btAdapter;

    private ListView scannedListView;
    private ListView pairedListView;
    private Button scanButton;
    private ArrayAdapter<String> scannedListAdapter;
    private ArrayAdapter<String> pairedListAdapter;
    private boolean bluetoothEnabled = false;



    private final BroadcastReceiver receiver = new BroadcastReceiver() {
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if (BluetoothDevice.ACTION_FOUND.equals(action)) {
                BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                onBluetoothDeviceFound(device);
            }
        }
    };

    @SuppressLint("MissingPermission")
    private void onBluetoothDeviceFound(BluetoothDevice device) {
        this.scannedDevices.add(device);
        if(device.getName()!= null){
            this.scannedNameList.add(device.getName());
        } else {
            this.scannedNameList.add(device.getAddress());
        }
        runOnUiThread(() -> scannedListAdapter.notifyDataSetChanged());
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        IntentFilter filter = new IntentFilter(BluetoothDevice.ACTION_FOUND);
        registerReceiver(receiver, filter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {

    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

    }

    @Override
    public boolean onSupportNavigateUp() {

    }
}