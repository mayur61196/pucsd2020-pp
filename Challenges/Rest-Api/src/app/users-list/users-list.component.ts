
import { Component, OnInit } from '@angular/core';
import { RestApiService } from "../shared/rest-api.service";

@Component({
  selector: 'app-users-list',
  templateUrl: './users-list.component.html',
  styleUrls: ['./users-list.component.css']
})
export class UsersListComponent implements OnInit {

  User: any = [];

  constructor(
    public restApi: RestApiService
  ) { }

  ngOnInit() {
    this.loadUsers()
  }
  getUserById(id: string) {
    return this.restApi.getUser(id).subscribe((data: {}) => {

      console.log(data);
      this.User = data;



    })
  }

  // Get users list
  loadUsers() {
    return this.restApi.getUsers().subscribe((data: {}) => {
      this.User = data;
    })
  }

  // Delete user
  deleteUser(id) {
    if (window.confirm('Are you sure, you want to delete?')){
      this.restApi.deleteUser(id).subscribe(data => {
        this.loadUsers()
      })
    }
  }  

}
