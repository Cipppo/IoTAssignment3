package com.example.room_mobile_app;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;

import com.google.android.material.snackbar.Snackbar;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.util.Log;
import android.view.View;

import androidx.core.app.ActivityCompat;
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

import android.Manifest;


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

    public static final String X_BLUETOOTH_DEVICE_EXTRA = "X_BLUETOOTH_DEVICE_EXTRA";
    private static final int REQUEST_ENABLE_BT = 1234;
    private static final int REQUEST_PERMISSION_CONNECT = 758;
    private static final int REQUEST_PERMISSION_SCAN = 759;



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

    @RequiresApi(api = Build.VERSION_CODES.M)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        IntentFilter filter = new IntentFilter(BluetoothDevice.ACTION_FOUND);
        registerReceiver(receiver, filter);

        this.initUI();
    }


    private void initUI(){
        scannedListView = findViewById(R.id.scannedView);

        scannedListAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, scannedNameList);
        scannedListView.setAdapter(scannedListAdapter);

        scannedListView.setOnItemClickListener((adapterView, view ,i, l) -> {
            onDeviceClicked(scannedDevices.get(i));
        });

        pairedListView = findViewById(R.id.pairedView);
        pairedListAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, pairedNameList);
        pairedListView.setAdapter(pairedListAdapter);

        pairedListView.setOnItemClickListener((adapterView, view, i, l) -> {
            onDeviceClicked(pairedDevices.get(i));
        });

        scanButton = findViewById(R.id.scan_button);
        scanButton.setOnClickListener((v) -> startScanning());
    }

    @RequiresApi(api = Build.VERSION_CODES.M)
    @Override
    protected void onStart(){
        btAdapter = getSystemService(BluetoothManager.class).getAdapter();
        if(btAdapter == null){
            displayError("Bluetooth Not supported !");
            finish();
        }
        super.onStart();
        this.scanButton.setEnabled(false);
        checkPermissionsAndEnableBluetooth();
    }

    @Override
    protected void onResume(){
        super.onResume();
        if(ActivityCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_CONNECT) != PackageManager.PERMISSION_GRANTED){
            displayError("Please be sure to grant permission first");
        }else{
            pairedDevices.clear();
            pairedNameList.clear();
            runOnUiThread(() -> pairedListAdapter.notifyDataSetChanged());
            pairedDevices.addAll(btAdapter.getBondedDevices());
            if(pairedDevices.size() > 0){
                for(BluetoothDevice device : pairedDevices){
                    if(device.getName() != null){
                        this.pairedNameList.add(device.getName());
                    }else{
                        this.pairedNameList.add(device.getAddress());
                    }
                    runOnUiThread(() -> pairedListAdapter.notifyDataSetChanged());
                }
            }
        }
    }

    @SuppressLint("MissingPermission")
    private void onDeviceClicked(BluetoothDevice device){
        logMessage(device.getName());
        Intent intent = new Intent(this, LedSwitchActivity.class);
        intent.putExtra(X_BLUETOOTH_DEVICE_EXTRA, device);
        startActivity(intent);
    }

    @RequiresApi(api = Build.VERSION_CODES.M)
    private void startScanning(){
        if(ActivityCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_SCAN) != PackageManager.PERMISSION_GRANTED){
            requestPermissions(new String[]{Manifest.permission.BLUETOOTH_SCAN}, REQUEST_PERMISSION_SCAN);
            return;
        }else{
            if(!btAdapter.isDiscovering()){
                this.checkPermissionsAndEnableBluetooth();
                scannedDevices.clear();
                scannedNameList.clear();
                runOnUiThread(() -> scannedListAdapter.notifyDataSetChanged());
                btAdapter.startDiscovery();
            }else{
                displayError("Already Scanning !");
            }
        }
    }

    @RequiresApi(api = Build.VERSION_CODES.M)
    private void checkPermissionsAndEnableBluetooth(){
        if(ActivityCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_SCAN) != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(new String[]{Manifest.permission.BLUETOOTH_SCAN}, REQUEST_PERMISSION_SCAN);
        }else{
            if(!btAdapter.isEnabled()) {
                Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enableBtIntent, REQUEST_ENABLE_BT);
            }else{
                this.scanButton.setEnabled(true);
            }
        }
    }

    @RequiresApi(api = Build.VERSION_CODES.M)
    @SuppressLint("MissingPermissions")
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults){
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch(requestCode){
            case REQUEST_PERMISSION_CONNECT:
                if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                    checkPermissionsAndEnableBluetooth();
                }else{
                    displayError("You need to grant bluetooth connection permission in order to use this app");
                }
                break;
            case REQUEST_PERMISSION_SCAN:
                if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                    startScanning();
                }else{
                    displayError("You need to grant bluetooth connection permission in order to use this app");
                }
                break;
            default:
                logMessage("result of unknown activity request");
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data){
        super.onActivityResult(requestCode, resultCode, data);
        switch(requestCode){
            case REQUEST_ENABLE_BT:
                if(resultCode == RESULT_OK){
                    this.scanButton.setEnabled(true);
                }else{
                    displayError("You need to enable Bluetooth to use the app");
                }
                break;
            default:
                logMessage("result of unknown activity request");
        }
    }

    private void displayError(String s){
        Log.e(C.TAG, s);
    }

    private void logMessage(String message){
        Log.i(C.TAG, message);
    }
}